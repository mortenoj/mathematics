package com.morten.maths;

import java.lang.Math;

class Vector3 {
    public var x: Float = Float.MAX_VALUE
    public var y: Float = Float.MAX_VALUE
    public var z: Float = Float.MAX_VALUE

    constructor(x: Float, y: Float, z: Float) {
        this.x = x
        this.y = y
        this.z = z
    }

    constructor() {}


    operator fun unaryMinus() = Vector3(-this.x, -this.y, -this.z)

    operator fun plus(v: Vector3): Vector3 {
        return Vector3(
            this.x + v.x,
            this.y + v.y,
            this.z + v.z
        )
    }

    operator fun minus(v: Vector3): Vector3 {
        return Vector3(
            this.x - v.x,
            this.y - v.y,
            this.z - v.z
        )
    }

    operator fun times(scalar: Float): Vector3 {
        return Vector3(
            this.x * scalar,
            this.y * scalar,
            this.z * scalar
        )
    }

    operator fun div(scalar: Float): Vector3 {
        return Vector3(
            this.x / scalar,
            this.y / scalar,
            this.z / scalar
        )
    }
 
    fun add(v: Vector3) {
        this.x += v.x
        this.y += v.y
        this.z += v.z
    }

    fun subtract(v: Vector3) {
        this.x -= v.x
        this.y -= v.y
        this.z -= v.z
    }

    fun length(): Float {
        return Math.sqrt((x*x + y*y + z*z).toDouble()).toFloat()
    }

    fun invert() {
        this.x = -this.x
        this.y = -this.y
        this.z = -this.z
    }

    fun multiplyScalar(scalar: Float) {
        this.x *= scalar
        this.y *= scalar
        this.z *= scalar
    }

    fun divideScalar(scalar: Float) {
        this.x /= scalar
        this.y /= scalar
        this.z /= scalar
    }

    fun dot(v: Vector3): Float {
        return this.x * v.x + this.y * v.y + this.z * v.z
    }

    fun cross(v: Vector3): Vector3 {
        return Vector3(
            this.y * v.z - this.z * v.y,
            this.z * v.x - this.x * v.z,
            this.x * v.y - this.y * v.x
        )
    }

    fun normalize() {
        val normalized = this / this.length()
        this.x = normalized.x
        this.y = normalized.y
        this.z = normalized.z
    }

    fun normalized(): Vector3 {
        return this / this.length()
    }

    override fun toString(): String {
        return "($x, $y, $z)"
    }
}
