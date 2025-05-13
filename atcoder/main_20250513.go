package main

// https://atcoder.jp/contests/abc367/tasks/abc367_d

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
	var n, m int
	Fscan(in, &n, &m)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		Fscan(in, &a[i])
	}
	cnt := make([]int, m+1)
	presum := make([]int, n)
	for i := 0; i < n; i++ {
		if i == 0 {
			presum[i] = a[i]

		} else {
			presum[i] = presum[i-1] + a[i]
		}
		presum[i] %= m
		if i < n-1 {
			cnt[presum[i]]++
		}
	}

	ans := cnt[0]
	for i := 1; i < n; i++ {
		cnt[presum[i-1]]--
		if i == 1 {
			cnt[(presum[n-1])%m]++
		} else {
			cnt[(presum[n-1]+presum[i-2])%m]++
		}

		ans += cnt[presum[i-1]]
	}
	Fprint(out, ans)
}

func main() {
	n := 1

	// n = readIntArray()[0]

	i := 0
	for ; i < n; i++ {
		solve(i, bufio.NewReader(os.Stdin), os.Stdout)
	}

}
