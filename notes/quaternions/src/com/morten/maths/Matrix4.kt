package com.morten.maths;

class Matrix4 {
    private var m: Array<Array<Float>> = arrayOf<Array<Float>>()

    constructor() {}

    constructor(m00: Float, m01: Float, m02: Float, m03: Float,
                m10: Float, m11: Float, m12: Float, m13: Float,
                m20: Float, m21: Float, m22: Float, m23: Float,
                m30: Float, m31: Float, m32: Float, m33: Float) {
        m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
        m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
        m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
        m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
    }

    fun identity() {
        for (i in 0 until 4)
            for (j in 0 until 4)
                m[i][j] = 0f
                
        m[0][0] = 1.0f
        m[1][1] = 1.0f
        m[2][2] = 1.0f
        m[3][3] = 1.0f
    }

}