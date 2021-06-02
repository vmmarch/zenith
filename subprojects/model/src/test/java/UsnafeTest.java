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

import com.zenith.Malloc;
import sun.misc.Unsafe;

/**
 * @author luots
 */
public class UsnafeTest {

    static Unsafe unsafe = Malloc.unsafe;

    public static void main(String[] args) {
        long address = Malloc.allocate(4);
        System.out.println("address = " + address);

        unsafe.putInt(address,100);

        System.out.println(unsafe.getInt(address));

        Malloc.free(address);

        System.out.println(unsafe.getInt(address));
    }

}
