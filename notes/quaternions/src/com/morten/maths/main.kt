package com.morten.maths;

// kotlinc src -include-runtime -d main.jar && java -jar main.jar
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

    val m1 = Matrix4(
        0f, 1f, 2f, 3f,
        12f, 13f, 2f, 3f,
        0f, 75f, 2f, 3.2f,
        0f, 9f, 2f, 3.2f
    )

    val m2 = Matrix4(
        0f, 1f, 2f, 3f,
        0f, 1f, 2f, 3f,
        0f, 1f, 2f, 3f,
        0f, 1f, 2f, 3f
    )

    println("m1 * m2: ${ m1 * m2 }")
}