package main

//https://codeforces.com/problemset/problem/2126/D

import (
	"bufio"
	. "fmt"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
	"sort"
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
	n:=0
	k:=0
	Fscan(in, &n)
	Fscan(in, &k)
	q:=make([][]int,n)
	for i:=0;i<n;i++{
		q[i] = make([]int,3)
		l:=0
		r:=0
		real:=0
		Fscan(in, &l)
		Fscan(in, &r)
		Fscan(in, &real)
		q[i][0] = l
		q[i][1] = r
		q[i][2] = real
	}
	sort.Slice(q, func(i int, j int)bool{
		return q[i][2]<q[j][2]
	})
	ans:=k
	for i:=0;i<n;i++{
		if q[i][0]<=ans && q[i][1]>=ans && q[i][2]>=ans{
			ans = q[i][2]
		}
	}
	fmt.Println(ans)
}

func main() {
	n := 1
	

	// n = readIntArray()[0]
	in:=bufio.NewReader(os.Stdin)
	Fscan(in, &n)

	i := 0
	for ; i < n; i++ {
		solve(i, in, os.Stdout)
	}

}
