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


import java.io.IOException;

/**
 * @author luots
 */
public class ModelMain {

    public static long domain(String path) throws IOException {
        if(checkObj(path))
        {
            ObjReader reader = new ObjReader(path);
            reader.parseModel();

            for (Group group : reader.getGroups()) {
                long address = Malloc.allocate(group.getVertices().length * 4L); // 分配内存
            }

        }
        return 0L;
    }

    private static boolean checkObj(String path)
    {
        return "obj".equals(Files.getExt(path));
    }

    private static void showVertices(Group group)
    {
        int count = 0;
        for (float vertex : group.getVertices()) {

            count++;

            if(count == 1) {
                System.out.print("XYZ: ");
                System.out.print(vertex);
            }

            if(count == 2)
            {
                System.out.print(" " + vertex);
            }

            if(count == 3)
            {
                System.out.println(" " + vertex);
                count = 0;
            }

        }
    }

}
