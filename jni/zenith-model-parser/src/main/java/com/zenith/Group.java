package com.zenith;

import com.zenith.vec.Vector2f;
import com.zenith.vec.Vector3f;
import com.zenith.vec.Vector3i;

import java.util.LinkedList;
import java.util.List;

public class Group {

    // 光化组
    private boolean smooth;

    // 顶点数据
    private List<Vector3f> vertices;

    // 纹理坐标
    private List<Vector2f> texcoords;

    // 法向量
    private List<Vector3f> normals;

    // 面
    private List<Vector3i> faces;

    // 当前模型总共有多少面
    private int faceCount = 0;

    public Group(boolean smooth,
                 List<Vector3f> vertices,
                 List<Vector2f> texcoords,
                 List<Vector3f> normals,
                 List<Vector3i> faces,
                 int faceCount) {
        this.smooth = smooth;
        this.vertices = vertices;
        this.texcoords = texcoords;
        this.normals = normals;
        this.faces = faces;
        this.faceCount = faceCount;
    }

    public boolean isSmooth() {
        return smooth;
    }

    public void setSmooth(boolean smooth) {
        this.smooth = smooth;
    }

    public List<Vector3f> getVertices() {
        return vertices;
    }

    public void setVertices(List<Vector3f> vertices) {
        this.vertices = vertices;
    }

    public List<Vector2f> getTexcoords() {
        return texcoords;
    }

    public void setTexcoords(List<Vector2f> texcoords) {
        this.texcoords = texcoords;
    }

    public List<Vector3f> getNormals() {
        return normals;
    }

    public void setNormals(List<Vector3f> normals) {
        this.normals = normals;
    }

    public List<Vector3i> getFaces() {
        return faces;
    }

    public void setFaces(List<Vector3i> faces) {
        this.faces = faces;
    }

    public int getFaceCount() {
        return faceCount;
    }

    public void setFaceCount(int faceCount) {
        this.faceCount = faceCount;
    }
}
