package main

import (
	"fmt"
	"io"
)

func main() {
	var n int

	for {
		_, err := fmt.Scanln(&n)
		if err == io.EOF || n == -1 {
			break
		}

		dp := [31][8]int{}
		dp[0][7] = 1;
		for i := 1; i < n+1; i++ {
			dp[i][0] += dp[i - 1][7]

			dp[i][1] += dp[i-1][6]

			dp[i][3] += dp[i-1][7]
			dp[i][3] += dp[i-1][4]

			dp[i][4] += dp[i-1][3]

			dp[i][6] += dp[i-1][7]
			dp[i][6] += dp[i-1][1]

			dp[i][7] += dp[i-1][3]
			dp[i][7] += dp[i-1][6]
			dp[i][7] += dp[i-1][0]
		}
		fmt.Println(dp[n][7])
	}
}