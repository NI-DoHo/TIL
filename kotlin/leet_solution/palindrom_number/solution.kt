class Solution {
	fun isPalindrome(x: Int): Boolean {
		if (x < 0) return false

		return x.toString() == x.toString().reversed()
	}
}

fun main() {
	var slt = Solution()

	println(slt.isPalindrome(121))
	println(slt.isPalindrome(-121))
	println(slt.isPalindrome(2147483647))
}
