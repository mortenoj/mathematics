package com.morten.maths

// https://github.com/BSVino/MathForGameDevelopers/blob/quaternion-transform/math/matrix.h
// https://github.com/BSVino/MathForGameDevelopers/blob/quaternion-transform/math/matrix.cpp
class Matrix4 {
    public var m: Array<Array<Float>> = Array(6) {Array(6) {0f} }

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

    override fun toString(): String {
        var ret = "\n(\n"
        for (i in 0 until 4) {
            ret += "\t"
            for (j in 0 until 4) {
                ret += "${m[i][j]}"
                if (!(i == 3 && j == 3)) ret += ", "
            }
            ret += "\n"
        }

        ret += ")"
        return ret
    }

    operator fun times(t: Matrix4): Matrix4 {
        val r = Matrix4()

        // [a b c d][A B C D]   [aA+bE+cI+dM
        // [e f g h][E F G H] = [eA+fE+gI+hM ...
        // [i j k l][I J K L]
        // [m n o p][M N O P]

        for (i in 0 until 4)
            for (j in 0 until 4)
                r.m[i][j] = m[0][j] * t.m[i][0] + m[1][j] * t.m[i][1] + m[2][j] * t.m[i][2] + m[3][j] * t.m[i][3]

        return r
    }

    operator fun times(f: Float): Matrix4 {
        val r = Matrix4();

        r.m[0][0] = m[0][0]*f
        r.m[0][1] = m[0][1]*f
        r.m[0][2] = m[0][2]*f
        r.m[0][3] = m[0][3]*f

        r.m[1][0] = m[1][0]*f
        r.m[1][1] = m[1][1]*f
        r.m[1][2] = m[1][2]*f
        r.m[1][3] = m[1][3]*f

        r.m[2][0] = m[2][0]*f
        r.m[2][1] = m[2][1]*f
        r.m[2][2] = m[2][2]*f
        r.m[2][3] = m[2][3]*f

        r.m[3][0] = m[3][0]*f
        r.m[3][1] = m[3][1]*f
        r.m[3][2] = m[3][2]*f
        r.m[3][3] = m[3][3]*f

        return r
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