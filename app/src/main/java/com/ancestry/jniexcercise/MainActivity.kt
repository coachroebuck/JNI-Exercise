package com.ancestry.jniexcercise

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View

class MainActivity : AppCompatActivity() {

    private val tag = this::class.java.simpleName

    private val callback = object : JniCallback{
        override fun onBoolean(value: Boolean) {
            Log.i(tag, "onBoolean=[${value}]")
        }

        override fun onByte(value: Byte) {
            Log.i(tag, "onByte=[${value}]")
        }

        override fun onChar(value: Char) {
            Log.i(tag, "onChar=[${value}]")
        }

        override fun onShort(value: Short) {
            Log.i(tag, "onShort=[${value}]")
        }

        override fun onInt(value: Int) {
            Log.i(tag, "onInt=[${value}]")
        }

        override fun onLong(value: Long) {
            Log.i(tag, "onLong=[${value}]")
        }

        override fun onFloat(value: Float) {
            Log.i(tag, "onFloat=[${value}]")
        }

        override fun onDouble(value: Double) {
            Log.i(tag, "onDouble=[${value}]")
        }

        override fun onString(value: String) {
            Log.i(tag, "onString=[${value}]")
        }

        override fun onObject(value: Any) {
            Log.i(tag, "onObject=[${value}]")
        }

        override fun onPerson(value: Person) {
            Log.i(tag, "onPerson=[${value}]")
        }

        override fun onBooleanArray(value: BooleanArray) {
            val sb = StringBuilder();
            value.map { sb.append("$it\t") }
            Log.i(tag, "onBooleanArray=[${sb.toString()}]")
        }

        override fun onByteArray(value: ByteArray) {
            val sb = StringBuilder();
            value.map { sb.append("$it\t") }
            Log.i(tag, "onByteArray=[${sb.toString()}]")
        }

        override fun onCharArray(value: CharArray) {
            val sb = StringBuilder();
            value.map { sb.append("$it\t") }
            Log.i(tag, "onCharArray=[${sb.toString()}]")
        }

        override fun onShortArray(value: ShortArray) {
            val sb = StringBuilder();
            value.map { sb.append("$it\t") }
            Log.i(tag, "onShortArray=[${sb.toString()}]")
        }

        override fun onIntArray(value: IntArray) {
            val sb = StringBuilder();
            value.map { sb.append("$it\t") }
            Log.i(tag, "onIntArray=[${sb.toString()}]")
        }

        override fun onLongArray(value: LongArray) {
            val sb = StringBuilder();
            value.map { sb.append("$it\t") }
            Log.i(tag, "onLongArray=[${sb.toString()}]")
        }

        override fun onFloatArray(value: FloatArray) {
            val sb = StringBuilder();
            value.map { sb.append("$it\t") }
            Log.i(tag, "onFloatArray=[${sb.toString()}]")
        }

        override fun onDoubleArray(value: DoubleArray) {
            val sb = StringBuilder();
            value.map { sb.append("$it\t") }
            Log.i(tag, "onDoubleArray=[${sb.toString()}]")
        }

        override fun onStringArray(value: Array<String>) {
            val sb = StringBuilder();
            value.map { sb.append("$it\t") }
            Log.i(tag, "onStringArray=[${sb.toString()}]")
        }

        override fun onObjectArray(value: Array<Any>) {
            val sb = StringBuilder();
            value.map { sb.append("$it\t") }
            Log.i(tag, "onObjectArray=[${sb.toString()}]")
        }

        override fun onPersonArray(value: Array<Person>) {
            val sb = StringBuilder();
            value.map { sb.append("$it\t") }
            Log.i(tag, "onPersonArray=[${sb.toString()}]")
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        Log.i(tag, "Callback Class Name=[${callback.javaClass.name}]")
        setCallback(callback)
    }

    fun onSendBoolean(v: View) {
        sendBoolean(true)
    }
    fun onSendByte(v: View) {
        sendByte(0x065)
    }
    fun onSendChar(v: View) {
        sendChar('a')
    }
    fun onSendShort(v: View) {
        sendShort(64)
    }
    fun onSendInt(v: View) {
        sendInt(12)
    }
    fun onSendLong(v: View) {
    sendLong(1234567)
    }
    fun onSendFloat(v: View) {
        sendFloat(128.0f)
    }
    fun onSendDouble(v: View) {
        sendDouble(256.0)
    }
    fun onSendString(v: View) {
        sendString("Michael Roebuck")
    }
    fun onSendObject(v: View) {
        sendObject(Any())
    }
    fun onSendPerson(v: View) {
        sendPerson(Person(
            firstName = "Michael",
            lastName = "Roebuck"
        ))
    }

    fun onSendBooleanArray(v: View) {
        val value = booleanArrayOf(true, false, false, false, true, true)
        sendBooleanArray(value)
    }
    fun onSendByteArray(v: View) {
        val value = byteArrayOf(38,32,59, 68, 79, 68)
        sendByteArray(value)
    }
    fun onSendCharArray(v: View) {
        val value = charArrayOf('w', 'x', 'y', 'Z', 'K', 'L', 'M')
        sendCharArray(value)
    }
    fun onSendShortArray(v: View) {
        val value = shortArrayOf(94, 39, 101, 111, 10, 77)
        sendShortArray(value)

    }
    fun onSendIntArray(v: View) {
        val value = intArrayOf(845, 3456, 483, 20039, 283)
        sendIntArray(value)
    }
    fun onSendLongArray(v: View) {
        val value = longArrayOf(3843L, 3377L, 3727L, 958L, 36L)
        sendLongArray(value)
    }
    fun onSendFloatArray(v: View) {
        val value = floatArrayOf(10.0f, 394.0f, 3884.545f, 938.25f, 105.26f)
        sendFloatArray(value)
    }

    fun onSendDoubleArray(v: View) {
        val value = doubleArrayOf(10.0, 384.04, 4838.34, 2994.60, 3406.75)
        sendDoubleArray(value)
    }

    fun onSendStringArray(v: View) {
        val value = arrayOf("Michael", "Roebuck", "Coach")
        sendStringArray(value)
    }

    fun onSendObjectArray(v: View) {
        val value = arrayOf(Any(), Any(), Any())
        sendObjectArray(value)
    }
    fun onSendPersonArray(v: View) {
        val value = arrayOf(
            Person(
                firstName = "Shaq"
            ),
            Person(
                firstName = "Coach",
                lastName = "Roebuck"
            ),
            Person(
                firstName = "Regina",
                lastName = "Snape"
            )
        )
        sendPersonArray(value)
    }

    fun onGetBoolean(v: View) {
        getBoolean(callback)
    }
    fun onGetByte(v: View) {
        getByte(callback)
    }
    fun onGetChar(v: View) {
        getChar(callback)
    }
    fun onGetShort(v: View) {
        getShort(callback)
    }
    fun onGetInt(v: View) {
        getInt(callback)
    }
    fun onGetLong(v: View) {
        getLong(callback)
    }
    fun onGetFloat(v: View) {
        getFloat(callback)
    }
    fun onGetDouble(v: View) {
        getDouble(callback)
    }
    fun onGetStringFromJni(v: View) {
        getStringFromJni(callback)
    }
    fun onGetObject(v: View) {
        getObject(callback)
    }
    fun onGetPerson(v: View) {
        getPerson(callback)
    }

    fun onGetBooleanArray(v: View) {
        getBooleanArray(callback)
    }
    fun onGetByteArray(v: View) {
    getByteArray(callback)
    }
    fun onGetCharArray(v: View) {
        getCharArray(callback)
    }
    fun onGetShortArray(v: View) {
        getShortArray(callback)
    }
    fun onGetIntArray(v: View) {
        getIntArray(callback)
    }
    fun onGetLongArray(v: View) {
        getLongArray(callback)
    }
    fun onGetFloatArray(v: View) {
        getFloatArray(callback)
    }
    fun onGetDoubleArray(v: View) {
        getDoubleArray(callback)
    }
    fun onGetStringArray(v: View) {
        getStringArray(callback)
    }
    fun onGetObjectArray(v: View) {
        getObjectArray(callback)
    }
    fun onGetPersonArray(v: View) {
        getPersonArray(callback)
    }

    internal interface JniCallback {
        fun onBoolean(value: Boolean)
        fun onByte(value: Byte)
        fun onChar(value: Char)
        fun onShort(value: Short)
        fun onInt(value: Int)
        fun onLong(value: Long)
        fun onFloat(value: Float)
        fun onDouble(value: Double)
        fun onString(value: String)
        fun onObject(value: Any)
        fun onPerson(value: Person)

        fun onBooleanArray(value: BooleanArray)
        fun onByteArray(value: ByteArray)
        fun onCharArray(value: CharArray)
        fun onShortArray(value: ShortArray)
        fun onIntArray(value: IntArray)
        fun onLongArray(value: LongArray)
        fun onFloatArray(value: FloatArray)
        fun onDoubleArray(value: DoubleArray)
        fun onStringArray(value: Array<String>)
        fun onObjectArray(value: Array<Any>)
        fun onPersonArray(value: Array<Person>)
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */

    private external fun stringFromJNI(): String

    private external fun setCallback(value: JniCallback)

    private external fun sendBoolean(value: Boolean)
    private external fun sendByte(value: Byte)
    private external fun sendChar(value: Char)
    private external fun sendShort(value: Short)
    private external fun sendInt(value: Int)
    private external fun sendLong(value: Long)
    private external fun sendFloat(value: Float)
    private external fun sendDouble(value: Double)
    private external fun sendString(value: String)
    private external fun sendObject(value: Any)
    private external fun sendPerson(value: Person)

    private external fun sendBooleanArray(value: BooleanArray)
    private external fun sendByteArray(value: ByteArray)
    private external fun sendCharArray(value: CharArray)
    private external fun sendShortArray(value: ShortArray)
    private external fun sendIntArray(value: IntArray)
    private external fun sendLongArray(value: LongArray)
    private external fun sendFloatArray(value: FloatArray)
    private external fun sendDoubleArray(value: DoubleArray)
    private external fun sendStringArray(value: Array<String>)
    private external fun sendObjectArray(value: Array<Any>)
    private external fun sendPersonArray(value: Array<Person>)

    private external fun getBoolean(callback: JniCallback)
    private external fun getByte(callback: JniCallback)
    private external fun getChar(callback: JniCallback)
    private external fun getShort(callback: JniCallback)
    private external fun getInt(callback: JniCallback)
    private external fun getLong(callback: JniCallback)
    private external fun getFloat(callback: JniCallback)
    private external fun getDouble(callback: JniCallback)
    private external fun getStringFromJni(callback: JniCallback)
    private external fun getObject(callback: JniCallback)
    private external fun getPerson(callback: JniCallback)

    private external fun getBooleanArray(callback: JniCallback)
    private external fun getByteArray(callback: JniCallback)
    private external fun getCharArray(callback: JniCallback)
    private external fun getShortArray(callback: JniCallback)
    private external fun getIntArray(callback: JniCallback)
    private external fun getLongArray(callback: JniCallback)
    private external fun getFloatArray(callback: JniCallback)
    private external fun getDoubleArray(callback: JniCallback)
    private external fun getStringArray(callback: JniCallback)
    private external fun getObjectArray(callback: JniCallback)
    private external fun getPersonArray(callback: JniCallback)

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
