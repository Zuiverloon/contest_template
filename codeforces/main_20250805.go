package main

// https://codeforces.com/problemset/problem/2014/D

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
	d:=0
	k:=0
	Fscan(in, &n)
	Fscan(in, &d)
	Fscan(in, &k)
	lmp:=make([]int,n+2)
	rmp:=make([]int,n+2)
	for i:=0;i<k;i++{
		ll:=0
		rr:=0
		Fscan(in,&ll)
		Fscan(in,&rr)
		lmp[ll]++
		rmp[rr]++
	}
	tmp:=0
	for i:=1;i<d;i++{
		tmp+=lmp[i]
	}
	mxdate := 1
	mxcnt:=-1
	mndate:=1
	mncnt:=0x3f3f3f3f
	for l:=1;l<=n;l++{
		r:=l+d-1
		if r>n{
			break
		}
		tmp+=lmp[r]
		tmp-=rmp[l-1]
		if tmp>mxcnt{
			mxdate = l
			mxcnt = tmp
		}
		if tmp<mncnt{
			mndate = l
			mncnt = tmp
		}

	}
	fmt.Printf("%d %d\n",mxdate, mndate)

}

// 5 4 3
// 3 5
// 1 5
// 1 3

// 3 1
// 2 4
// 1 2
// 1 1
// 2 1
// 1 1
// 3 1
// 1 1
// 1 1
// 1 1
// 1 1
// 3 1

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
