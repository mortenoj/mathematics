package com.morten.maths;

class Quaternion {
    public var w: Float = -1f
    public lateinit var v: Vector3

    constructor(n: Vector3, a: Float) {
        val aRad: Double = Math.toRadians(a.toDouble())
        this.w = Math.cos(aRad / 2).toFloat()
        this.v = n * Math.sin(aRad / 2).toFloat()
    }

    constructor(w: Float, x: Float, y: Float, z: Float) {
        this.w = w
        this.v = Vector3(x, y, z)
    }

    constructor() {}

    override fun toString(): String {
        return "($w, $v)"
    }

    fun inverted(): Quaternion {
        val q = Quaternion()
        q.w = this.w
        q.v = -this.v
        return q
    }

    operator fun times(q: Quaternion): Quaternion {
        val r = Quaternion()
        r.w = this.w * q.w + this.v.dot(q.v)
        r.v = this.v * q.w + q.v * this.w + v.cross(q.v)
        return r
    }

    operator fun times(V: Vector3): Vector3 {
        val p = Quaternion()
        p.w = 0f
        p.v = V
        val q: Quaternion = this
	    return (q * p * q.inverted()).v;
    }
}

// kotlinc src -include-runtime -d Quaternion.jar && java -jar Quaternion.jar
fun main(args: Array<String>) {
    val q1 = Quaternion(Vector3(0f, 1f, 0f), 90f)
    val q2 = Quaternion(Vector3(1f, 0f, 0f), 45f)
    val q3 = q2 * q1

    println("q1: $q1 \n")
    println("q2: $q2 \n")
    println("q1 * q2 = q3: " + q3 + " \n")
    
    println("q3 * vector(1, 0, 0): ${ q3 * Vector3(1f, 0f, 0f) } \n")

    println("q1 * vector(1, 0, 0): ${ q1 * Vector3(1f, 0f, 0f) } \n")
    println("q2 * vector(0, 0, 1): ${ q2 * Vector3(0f, 0f, 1f) } \n")

    val euler = EulerAngle(10f, 0f, 20f)
    println("euler: ${euler.toVector()}")
}