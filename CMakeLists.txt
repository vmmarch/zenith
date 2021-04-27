cmake_minimum_required(VERSION 3.17)
project(zenith)

option(FUCK_STD "dont use sb std." ON)

if (FUCK_STD)
    add_subdirectory(fuckstd)
endif ()

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith SOURCE)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/init SOURCE_INIT)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/window SOURCE_WIN)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/event SOURCE_EVENT)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/platform SOURCE_PLATFORM)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/platform/windows SOURCE_PLATFORM_WINDOWS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/platform/opengl SOURCE_PLATFORM_OPENGL)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/render SOURCE_RENDER)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/tool SOURCE_TOOL)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/layer SOURCE_LAYER)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/render/texture SOURCE_TEXTURE)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/render/shader SOURCE_SHADER)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/models SOURCE_MODELS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/scene/3d/camera SOURCE_SCENE_3D_CAMERA)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/render/2d/texture SOURCE_RENDER_2D_CAMERA)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/buf SOURCE_BUF)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/sandbox SOURCE_SANDBOX)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/example SOURCE_EXAMPLE)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/load SOURCE_LOAD)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/japi SOURCE_JAPI)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/3DS SOURCE_3DS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/AC SOURCE_AC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/AMF SOURCE_AMF)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/ASE SOURCE_ASE)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Assjson SOURCE_Assjson)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/B3D SOURCE_B3D)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/BVH SOURCE_BVH)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/C4D SOURCE_C4D)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/CApi SOURCE_CApi)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/COB SOURCE_COB)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Collada SOURCE_Collada)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Common SOURCE_Common)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/CSM SOURCE_CSM)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/DXF SOURCE_DXF)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/FBX SOURCE_FBX)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/glTF SOURCE_glTF)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/glTF2 SOURCE_glTF2)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/HMP SOURCE_HMP)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Importer SOURCE_Importer)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Irr SOURCE_Irr)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/LWO SOURCE_LWO)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/LWS SOURCE_LWS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Material SOURCE_Material)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/MD2 SOURCE_MD2)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/MD3 SOURCE_MD3)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/MD4 SOURCE_MD4)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/MD5 SOURCE_MD5)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/MDC SOURCE_MDC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/MDL SOURCE_MDL)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/MMD SOURCE_MMD)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/MS3D SOURCE_MS3D)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/NDO SOURCE_NDO)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/NFF SOURCE_NFF)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Obj SOURCE_Obj)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/OFF SOURCE_OFF)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Ogre SOURCE_Ogre)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/OpenGEX SOURCE_OpenGEX)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Ply SOURCE_Ply)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/PostProcessing SOURCE_PostProcessing)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Q3BSP SOURCE_Q3BSP)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Q3D SOURCE_Q3D)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Raw SOURCE_Raw)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/res SOURCE_res)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/SIB SOURCE_SIB)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/SMD SOURCE_SMD)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Step SOURCE_Step)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/STL SOURCE_STL)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Terragen SOURCE_Terragen)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/Unreal SOURCE_Unreal)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/X SOURCE_X)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/X3D SOURCE_X3D)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/model-type/XGL SOURCE_XGL)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/assimp/irrXML SOURCE_irrXML)

include_directories(SYSTEM fuckstd)

# ---------------------------------------------------------------------------------------
# for assimp dir.
# ---------------------------------------------------------------------------------------
include_directories(SYSTEM assimp/irrXML)
include_directories(SYSTEM model-type)

# ---------------------------------------------------------------------------------------
# for modules dir.
# ---------------------------------------------------------------------------------------
include_directories(SYSTEM modules)
include_directories(SYSTEM modules/imgui)
include_directories(SYSTEM modules/imgui/backends)

# ---------------------------------------------------------------------------------------
# for include dir.
# ---------------------------------------------------------------------------------------
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(SYSTEM include/api)

# ---------------------------------------------------------------------------------------
# for jvm dir.
# ---------------------------------------------------------------------------------------
include_directories(SYSTEM include/jvm/win64)

# ---------------------------------------------------------------------------------------
# for src dir.
# ---------------------------------------------------------------------------------------
include_directories(zenith)

# ---------------------------------------------------------------------------------------
# 配置源码目录 SOURCEALL_DIR
# ---------------------------------------------------------------------------------------
aux_source_directory(${CMAKE_SOURCE_DIR} SOURCE_DIRECTORY)

set(CMAKE_CXX_STANDARD 20)

add_definitions(
        -D__ZENITH_PLATFORM_WINDOWS__                   # 编译平台为Windows
        -D__ZENITH_IN_CHINA__       # 引擎语言为中文
        -D__ZENITH_RENDERAPI_OPENGL__           # 引擎渲染API使用OpenGL
        -D__DEBUG__                   # 开启DEBUG
)

link_libraries(imm32)
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/bin/glfw3.dll)

add_executable(${PROJECT_NAME}
        ${SOURCE}
        ${SOURCE_INIT}
        ${SOURCE_WIN}
        ${SOURCE_EVENT}
        ${SOURCE_PLATFORM}
        ${SOURCE_PLATFORM_WINDOWS}
        ${SOURCE_PLATFORM_OPENGL}
        ${SOURCE_RENDER}
        ${SOURCE_TOOL}
        ${SOURCE_LAYER}
        ${SOURCE_TEXTURE}
        ${SOURCE_SHADER}
        ${SOURCE_MODELS}
        ${SOURCE_SCENE_3D_CAMERA}
        ${SOURCE_RENDER_2D_CAMERA}
        ${SOURCE_BUF}
        ${SOURCE_SANDBOX}
        ${SOURCE_EXAMPLE}
        ${SOURCE_LOAD}
        ${SOURCE_JAPI}
        ${LOADER_JVM_CALL}
        ${ASSIMP_OBJ}

        ${SOURCE_3DS}
        ${SOURCE_AC}
        ${SOURCE_AMF}
        ${SOURCE_ASE}
        ${SOURCE_Assjson}
        ${SOURCE_B3D}
        ${SOURCE_BVH}
        ${SOURCE_C4D}
        ${SOURCE_CApi}
        ${SOURCE_COB}
        ${SOURCE_Collada}
        ${SOURCE_Common}
        ${SOURCE_CSM}
        ${SOURCE_DXF}
        ${SOURCE_FBX}
        ${SOURCE_glTF}
        ${SOURCE_glTF2}
        ${SOURCE_HMP}
        ${SOURCE_Importer}
        ${SOURCE_Irr}
        ${SOURCE_LWO}
        ${SOURCE_LWS}
        ${SOURCE_Material}
        ${SOURCE_MD2}
        ${SOURCE_MD3}
        ${SOURCE_MD4}
        ${SOURCE_MD5}
        ${SOURCE_MDC}
        ${SOURCE_MDL}
        ${SOURCE_MMD}
        ${SOURCE_MS3D}
        ${SOURCE_NDO}
        ${SOURCE_NFF}
        ${SOURCE_Obj}
        ${SOURCE_OFF}
        ${SOURCE_Ogre}
        ${SOURCE_OpenGEX}
        ${SOURCE_Ply}
        ${SOURCE_PostProcessing}
        ${SOURCE_Q3BSP}
        ${SOURCE_Q3D}
        ${SOURCE_Raw}
        ${SOURCE_res}
        ${SOURCE_SIB}
        ${SOURCE_SMD}
        ${SOURCE_Step}
        ${SOURCE_STL}
        ${SOURCE_Terragen}
        ${SOURCE_Unreal}
        ${SOURCE_X}
        ${SOURCE_X3D}
        ${SOURCE_XGL}

        ${SOURCE_irrXML}

        # ---------------------------------------------------------------------------------------
        # IMGUI
        # ---------------------------------------------------------------------------------------
        ${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/imgui.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/imgui_draw.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/imgui_demo.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/imgui_widgets.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/imgui_tables.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/backends/imgui_impl_glfw.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/backends/imgui_impl_opengl3.cpp
        )

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/bin/assimp-vc142-mtd.dll)

install(
        TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}
)
