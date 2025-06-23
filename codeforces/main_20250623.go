// https://codeforces.com/problemset/problem/2117/C

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
	cnt := make([]int, n+1)
	distinct := 0
	for i := 0; i < n; i++ {
		Fscan(in, &v[i])
		cnt[v[i]]++
		if cnt[v[i]] == 1 {
			distinct++
		}
	}
	predistinct := distinct
	tmpcnt := make(map[int]int)
	ans := 0
	for i := n - 1; i >= 0; i-- {
		tmpcnt[v[i]]++
		cnt[v[i]]--
		if cnt[v[i]] == 0 {
			distinct--
		}
		if len(tmpcnt) == predistinct {
			ans++
			tmpcnt = make(map[int]int)
			predistinct = distinct

		}
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
