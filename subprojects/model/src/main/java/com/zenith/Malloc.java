package com.zenith;

import sun.misc.Unsafe;

import java.lang.reflect.Field;

/**
 * 内存写入
 */
@SuppressWarnings("ConstantConditions")
public class Malloc {

    public static final Unsafe unsafe = reflectGetUnsafe();

    private static Unsafe reflectGetUnsafe() {
        try {
            Field field = Unsafe.class.getDeclaredField("theUnsafe");
            field.setAccessible(true);
            return (Unsafe) field.get(null);
        } catch (Exception e) {
            e.printStackTrace();
        }

        return null;
    }

    /**
     * 分配内存
     * @param size 内存大小
     * @return 内存指针
     */
    public static long allocate(long size)
    {
        return unsafe.allocateMemory(size);
    }

    /**
     * 释放内存
     * @param address 指针
     */
    public static void free(long address)
    {
        unsafe.freeMemory(address);
    }

}
