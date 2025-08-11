package main

// https://codeforces.com/problemset/problem/1585/C

import (
	"bufio"
	. "fmt"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
	// "sync"
	"sort"
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





func solve(cas int, in io.Reader, out io.Writer) {
	n:=0
	k:=0
	Fscan(in, &n)
	Fscan(in, &k)
	pos:=make([]int,0)
	neg:=make([]int,0)
	tot:=make([]int,0)
	for i:=0;i<n;i++ {
		t:=0
		Fscan(in,&t)
		if t>0 {
			pos = append(pos,t)
		} else {
			neg = append(neg,t)
		}
	}
	sort.Slice(pos, func(i int, j int)bool {
		return pos[i]>pos[j]
	});
	sort.Slice(neg, func(i int, j int)bool {
		return neg[i]<neg[j]
	});

	p:=0
	for p<len(pos) {
		tot = append(tot, pos[p])
		p+=k
	}
	p = 0
	for p<len(neg) {
		tot = append(tot, abs(neg[p]))
		p+=k
	}
	sort.Slice(tot, func(i int, j int)bool {
		return tot[i]<tot[j]
	})
	ans:=0
	for i:=0;i<len(tot);i++{
		ans+=tot[i]*2
	}
	if len(tot)>0{
		ans-=tot[len(tot)-1]

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
