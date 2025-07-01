// https://codeforces.com/problemset/problem/2098/E
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

func solve(cas int, in io.Reader, out io.Writer) {
	// start from the back
	// if current interval[i..j] already contains all distinct element[0..j], we find a valid interval
	n := 1
	Fscan(in, &n)
	v := make([]int, n)
	one := make([]int, 32)
	zero := make([]int, 32)
	for i := 0; i < n; i++ {
		Fscan(in, &v[i])
		j := 0
		for t := v[i]; t > 0; t >>= 1 {
			if t&1 == 1 {
				one[j]++
			} else {
				zero[j]++
			}
			j += 1
		}
		for ; j < 32; j++ {
			zero[j]++
		}
	}
	ans := 0
	for i := 0; i < n; i++ {
		tans := 0
		base := 1
		j := 0
		for t := v[i]; t > 0; t >>= 1 {
			if t&1 == 1 {
				tans += zero[j] * base
			} else {
				tans += one[j] * base
			}
			j++
			base <<= 1
		}
		for ; j < 32; j++ {
			tans += one[j] * base
			base <<= 1
		}
		ans = max(ans, tans)
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
