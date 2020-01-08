class Solution {
	fun reverse(x: Int): Int {
		val IntMax = 2_147_483_647                                                                   
		val IntMin = -2_147_483_648                                                                  
		var y: Long = x.toLong()                                                                     

		if ((y >= 0 && y.toString().reversed().toLong() > IntMax) || (y < 0 && ((y * -1).toString().reversed().toLong() * -1) < IntMin)) return 0

		if (x >= 0) return x.toString().reversed().toInt()                                           
		else return (x * -1).toString().reversed().toInt() * -1                                      
	}
}

fun main() {
	val slt = Solution()

	if (slt.reverse(123) == 321) println("Pass plus case")
	if (slt.reverse(-123) == -321) println("Pass minus case")
	if (slt.reverse(120) == 21) println("Pass empty case")
	if (slt.reverse(1534236469) == 0) println("Pass OVF case")
	if (slt.reverse(-2147483648) == 0) println("Pass DUF case")
}
