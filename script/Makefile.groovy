def s = System.currentTimeMillis()
// ================================================================================================
// base config
def curdir = new File(new File(getClass().protectionDomain.codeSource.location.path).parent)

def CXX = "g++"
def INCLUDE = "-I${curdir.parent}/include -I."
def LIB = "-L${curdir.parent}/library"
def DEFINE = "-D__XM_PLATFORM_WINDOWS__ -D__IN_CHINA__"
def BUILD_OUTPUT = "../build-debug"
def BUILD_NAME = "application.dll"

// ================================================================================================
// function define
def fsl(File file, List<String> sources) {
    file.listFiles().each { f ->
        if (f.isDirectory()) {
            fsl(f, sources)
        } else {
            def name = f.name
            if (name.endsWithAny("c", "cpp"))
                sources.add f.path
        }
    }
}

def printline(String name, Closure closure)
{
    println ""
    println "// =============================================================================="
    println "// ${name} - START"
    closure.call()
    println "// ${name} - END"
    println "// =============================================================================="
    println ""
}

// ================================================================================================
// find source list for *.c *.cpp
List<String> SOURCES = [] // source path list
fsl(curdir, SOURCES)

printline("BUILD FILES", {
    SOURCES.forEach { name ->
        println name.replace("${curdir.path}\\", "")
    }
})

def SOURCES_PATH = SOURCES.toString()
        .replace("[", "")
        .replace("]", "")
        .replace(",", "")

// ================================================================================================
// build
def comm = "${CXX} -shared -o ${BUILD_NAME} ${SOURCES_PATH} ${INCLUDE} ${DEFINE} ${LIB} -lglfw3"
        .replace("\\", "/")

printline("EXECUTE COMMAND", {
    println comm
})

println "Start execute..."
def proc = comm.execute()
proc.waitFor()

println comm
println "${proc.err.text}"
println "${proc.in.text}"
println "exit code: ${proc.exitValue()}"

def e = System.currentTimeMillis()
println "BUILD USE ${e - s}MS"