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

import java.io.*;

/**
 * 抽象模型加载器
 *
 * @author luots
 */
public abstract class ModelReader {

    protected File M_FILE;

    protected BufferedReader reader;

    /**
     * 模型加载器构造
     *
     * @param path 模型地址
     */
    public ModelReader(String path) {
        this.M_FILE = new File(path);

        try {
            this.reader = new BufferedReader(new FileReader(M_FILE));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 解析模型
     */
    public abstract void parseModel();

    /**
     * 关闭IO流
     *
     * @throws IOException IO异常
     */
    public void close() throws IOException {
        reader.close();
    }

}
