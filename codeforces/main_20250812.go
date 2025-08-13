package main

// https://codeforces.com/problemset/problem/2053/C

import (
	"bufio"
	. "fmt"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
	// "sync"
	// "sort"
	// "math"
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

func gcd(x int, y int) int {
	if x<0{
		return gcd(-x,y)
	}
	if y< 0{
		return gcd(x,-y)
	}
	if x == 0 {
		return y
	}
	return gcd(y%x,x)
}

func abs(x int) int {
	if x<0 {
		return -x
	}
	return x
}

func max(x int, y int) int {
	if x>y {
		return x
	} else {
		return y
	}
}

func min(x int, y int) int {
	if x>y {
		return y
	} else {
		return x
	}
}


func f(n int, k int)(int, int) {
	if k>n {
		return 0,0
	}
	l1:=n/2
	l2:=n%2
	tans, tcnt:=f(l1,k)
	return tans*2+(tcnt+l2)*(l1+l2), tcnt*2+l2
}





func solve(cas int, in io.Reader, out io.Writer) {
	n,k:=0,0
	Fscan(in, &n)
	Fscan(in, &k)
	ans,_ := f(n,k)
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
