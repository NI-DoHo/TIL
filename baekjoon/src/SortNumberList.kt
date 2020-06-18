
const val MAX_SIZE = 10_000

fun main() {
    val numberArraySize = readLine()?.toInt() ?: 0
    var numberArrayCount = 0

    val numberArray = IntArray(MAX_SIZE + 1) { (MAX_SIZE + 1) * 0 }
    val bufferedReader = System.`in`.bufferedReader()
    val bufferedWriter = System.`out`.bufferedWriter()

    //println("Number array size : $numberArraySize")

    bufferedReader.useLines {
        it.forEach { number ->
            numberArray[number.toInt()] += 1

            numberArrayCount++
            //println("Input : $number [$numberArrayCount/$numberArraySize]")
            if (numberArrayCount == numberArraySize) return@useLines
        }
    }

    bufferedWriter.use {
        for (x in 1..MAX_SIZE) {
            if (numberArray[x] != 0) {
                bufferedWriter.write("$x\n".repeat(numberArray[x]))
            }
        }
        bufferedWriter.flush()
    }
}
