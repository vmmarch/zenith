package com.zenith;

/* ************************************************************************
 *
 * Copyright (C) 2020 2B键盘 All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ************************************************************************/

/*
 * Creates on 2020/6/1.
 */

import com.zenith.vec.Vector2f;
import com.zenith.vec.Vector3f;
import com.zenith.vec.Vector3i;

import java.io.IOException;
import java.util.LinkedList;
import java.util.List;

/**
 * @author luots
 */
public class ObjReader extends ModelReader {

    public ObjReader(String path) {
        super(path);
    }

    @Override
    public void parseModel() throws IOException {

        // 光化组
        boolean smooth = false;

        // 顶点数据
        List<Vector3f> vertices = new LinkedList<>();
        // 纹理坐标
        List<Vector2f> texcoords = new LinkedList<>();
        // 法向量
        List<Vector3f> normals = new LinkedList<>();
        // 面
        List<Vector3i> faces = new LinkedList<>();

        // 当前模型总共有多少面
        int faceCount = 0;

        String line;
        while ((line = reader.readLine()) != null) {
            if (line.startsWith("v")) {
                // texture vertex
                if (line.startsWith("vt")) {
                    String substring = line.substring(2).trim();
                    texcoords.add(Vector2f.toVec2f(substring.split(" ")));
                }

                // vertices normals
                if (line.startsWith("vn")) {
                    String substring = line.substring(2).trim();
                    normals.add(Vector3f.toVec3f(substring.split(" ")));
                }

                if (line.startsWith("vp")) {
                    continue;
                }

                // vertex
                String vertex = line.substring(1).trim();
                vertices.add(Vector3f.toVec3f(vertex.split(" ")));
            }

            // smooth
            if (line.startsWith("s")) {
                smooth = "off".equals(line.substring(1).trim());
            }

            // face
            // 顶点索引/uv索引/法线索引
            if (line.startsWith("f")) {
                String face_str = line.substring(1).trim();
                String[] faceArray = face_str.split(" ");
                faceCount += faceArray.length;

                // 解析face
                for (String face : faceArray) {
                    // 0: 顶点索引，1: UV索引，2: 法线索引
                    String[] property = face.split("/");
                    faces.add(Vector3i.toVec3i(property));
                }
            }
        }

        close();
    }

}
