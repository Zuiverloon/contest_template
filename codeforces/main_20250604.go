// https://codeforces.com/problemset/problem/1994/C

package main

import (
	"bufio"
	"fmt"
	. "fmt"
	"io"
	"os"
)

// func readLine() string {
// 	reader := bufio.NewReader(os.Stdin)
// 	text, _ := reader.ReadString('\n')
// 	return strings.Trim(text, "\n")
// }

// func printArr(arr []int) {
// 	n := len(arr)
// 	for id, i := range arr {
// 		Printf("%d", i)
// 		if id < n-1 {
// 			Printf(" ")
// 		} else {
// 			Printf("\n")
// 		}
// 	}
// }

// func readIntArray() []int {
// 	text := readLine()
// 	sli := strings.Split(text, " ")
// 	ret := make([]int, len(sli))
// 	for i, s := range sli {
// 		ret[i], _ = strconv.Atoi(s)
// 	}
// 	return ret
// }

// func readInt() int {
// 	text := readLine()
// 	ret, _ := strconv.Atoi(text)
// 	return ret
// }

// func readStringArray() []string {
// 	text := readLine()
// 	sli := strings.Split(text, " ")
// 	ret := make([]string, len(sli))
// 	for i, s := range sli {
// 		ret[i] = s
// 	}
// 	return ret
// }

func ioSample(in io.Reader, out io.Writer) {
	var x, y int
	Fscan(in, &x, &y)

	Fprint(out, 1)
}

func bs(presum []int64, pre int64, j int, x int64) int {
	l := j
	r := len(presum) - 1
	ans := len(presum)
	for l <= r {
		mid := (l + r) / 2
		if presum[mid]-pre > x {
			r = mid - 1
			ans = mid
		} else {
			l = mid + 1
		}
	}
	return ans
}

func solve(cas int, in io.Reader, out io.Writer) {
	// f[i]                  // the number of pairs starting with i
	// f[i] = (j - i) + f[j] // j sum(i..j)>g how to search j ? binary search with presum
	// ans = sum(f[0],f[1],...,f[n-1])
	var n int
	var x int64
	Fscan(in, &n, &x)
	v := make([]int64, n)
	presum := make([]int64, n)
	f := make([]int64, n)
	var ans int64
	ans = 0
	for i := 0; i < n; i++ {
		Fscan(in, &v[i])
		if i == 0 {
			presum[i] = v[i]
		} else {
			presum[i] = v[i] + presum[i-1]
		}
	}
	for i := n - 1; i >= 0; i-- {
		j := 0
		if i != 0 {
			j = bs(presum, presum[i-1], i, x)
		} else {
			j = bs(presum, 0, i, x)
		}
		//fmt.Println("j=", j)
		if j >= n {
			f[i] = int64(n - 1 - i + 1)
		} else if j+1 <= n-1 {
			f[i] = int64(j-i) + (f[j+1])
		} else {
			f[i] = int64(j - i)
		}
		//fmt.Println(i, f[i])
		ans += f[i]
	}
	fmt.Println(ans)
}

func main() {
	n := 1
	input := bufio.NewReader(os.Stdin)
	output := os.Stdout
	Fscan(input, &n)

	i := 0
	for ; i < n; i++ {
		solve(i, input, output)
	}

}
