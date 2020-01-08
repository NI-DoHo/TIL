class Solution {
	fun myAtoi(str: String): Int {
		var tmp = str
		val IntMin = "-2147483648"
		val IntMax = "2147483647"

		// Get first word
		for (substring in tmp.split(" ")) {
			if (substring != "") {
				tmp = substring
				break
			}
		}

		// Check word, Replace letter (non-numeric) to space
		for (letter in tmp) {
			if ((letter < '0' || '9' < letter) && (letter != '+' && letter != '-'))
				tmp = tmp.replace(letter.toString(), " ")
		}

		// Get first word
		tmp = tmp.split(" ")[0]

		if (tmp.length == 0) return 0
		else if (tmp.substring(1).contains("-")) 
			tmp = tmp.substring(0, tmp.substring(1).indexOf("-") + 1)
		else if (tmp.substring(1).contains("+")) 
			tmp = tmp.substring(0, tmp.substring(1).indexOf("+") + 1)

		// Delete unmeaningful zero padding
		for (letter in tmp) {
			if (tmp.length == 1) break
			else if (tmp.substring(0, 2) == "-0") tmp = tmp.replace("-0", "-")
			else if (tmp.substring(0, 2) == "00") tmp = tmp.substring(1)
			else if (tmp.substring(0, 1) == "+") tmp = tmp.substring(1)
		}

		// Return
		//println(tmp)
		if (tmp == "" || tmp == "+" || tmp == "-" || tmp.contains("+-") || tmp.contains("-+"))
			return 0
		else if (tmp[0] == '-' && (tmp.length > IntMin.length || tmp.toLong() < IntMin.toLong())) 
			return IntMin.toInt()
		else if (tmp[0] != '-' && (tmp.length > IntMax.length || tmp.toLong() > IntMax.toLong()))
			return IntMax.toInt()
		else 
			return tmp.toInt()
	}
}

fun main() {
	var slt = Solution()

	println(slt.myAtoi("-42-"))
	println(slt.myAtoi("42+"))
	println(slt.myAtoi(" 42"))
	println(slt.myAtoi(" -42"))
	println(slt.myAtoi("2147483648"))
	println(slt.myAtoi("-2147483647"))
	println(slt.myAtoi("20000000000000000000"))
	println(slt.myAtoi("words and 987"))
	println(slt.myAtoi("-"))
	println(slt.myAtoi("+"))
	println(slt.myAtoi("0000123"))
	println(slt.myAtoi(" -0000123"))
	println(slt.myAtoi("3.14"))
	println(slt.myAtoi(".14"))
	println(slt.myAtoi("0000000000000000000000000000"))
	println(slt.myAtoi("    +1146905820n1"))
}
