package com.morten.maths;

class EulerAngle {
    // Pitch, yaw, roll
    public var pitch: Float = Float.MAX_VALUE
    public var yaw: Float = Float.MAX_VALUE
    public var roll: Float = Float.MAX_VALUE

    constructor() {
        this.pitch = 0f
        this.yaw = 0f
        this.roll = 0f
    }

    constructor(pitch: Float, yaw: Float, roll: Float) {
        this.pitch = pitch
        this.yaw = yaw
        this.roll = roll
    }

    fun toVector(): Vector3 {
        val y2: Double = this.yaw.toDouble() / 360 * 2 * Math.PI
        val p2: Double = this.pitch.toDouble() / 360 * 2 * Math.PI
        
        return Vector3(
            (Math.cos(y2) * Math.cos(p2)).toFloat(),
            (Math.sin(p2)).toFloat(),
            (Math.sin(y2) * Math.cos(p2)).toFloat()
        )
    }

    fun normalize() {
        if (this.pitch > 89f) {
            this.pitch = 89f
        }

        while (this.yaw > 180f) {
            this.yaw -= 360f
        }   

        if (this.pitch < -89f) {
            this.pitch = -89f
        }

        while (this.yaw < -180f) {
            this.yaw += 360f
        }
    }
}