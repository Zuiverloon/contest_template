/**
https://codeforces.com/problemset/problem/708/A
*/

package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	text, _ := reader.ReadString('\n')
	return strings.Trim(text, "\n")
}

func printArr(arr []int) {
	n := len(arr)
	for id, i := range arr {
		Printf("%d", i)
		if id < n-1 {
			Printf(" ")
		} else {
			Printf("\n")
		}
	}
}

func readIntArray() []int {
	text := readLine()
	sli := strings.Split(text, " ")
	ret := make([]int, len(sli))
	for i, s := range sli {
		ret[i], _ = strconv.Atoi(s)
	}
	return ret
}

func readInt() int {
	text := readLine()
	ret, _ := strconv.Atoi(text)
	return ret
}

func readStringArray() []string {
	text := readLine()
	sli := strings.Split(text, " ")
	ret := make([]string, len(sli))
	for i, s := range sli {
		ret[i] = s
	}
	return ret
}

func solve(cas int, in io.Reader, out io.Writer) {
	var s string
	Fscan(in, &s)
	start := 0
	for start < len(s) {
		if s[start] == 'a' {
			start++
		} else {
			break
		}
	}
	if start == len(s) {
		start = len(s) - 1
	}
	end := start + 1
	for end < len(s) {
		if s[end] != 'a' {
			end++
		} else {
			break
		}
	}
	// for i := start; i < end; i++ {
	// 	s[i] = s[i] - 1
	// }
	ans := make([]byte, len(s))
	for i := 0; i < len(s); i++ {
		if i >= start && i < end {
			ans[i] = s[i] - 1
			if ans[i] < 'a' {
				ans[i] = 'z'
			}
		} else {
			ans[i] = s[i]
		}
	}
	Fprint(out, string(ans))

}

func main() {
	n := 1
	input := bufio.NewReader(os.Stdin)
	Fscan(input, &n)

	i := 0
	for ; i < n; i++ {
		solve(i, input, os.Stdout)
	}

}
