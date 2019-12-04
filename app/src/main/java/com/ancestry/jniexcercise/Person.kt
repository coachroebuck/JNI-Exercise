package com.ancestry.jniexcercise

import java.lang.StringBuilder

data class Person(
    @JvmField val firstName: String? = null,
    @JvmField val lastName: String? = null
) {
    override fun toString(): String {
        val sb = StringBuilder()
        sb.append("firstName=[$firstName] ")
        sb.append("lastName=[$lastName] ")
        return sb.toString()
    }
}