package main

/**
https://codeforces.com/problemset/problem/2129/B
**/

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

func printYes() {
	fmt.Println("Yes")
}

func printNo() {
	fmt.Println("No")
}

func sortExample() {
	arr:=[]int{2,3,4}
	sort.Slice(arr, func(i int, j int)bool{
		return arr[i]<arr[j]
	})
}

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


func lowbit(i int)int {
	return i & (-i)
}

func add(ft []int, pos int, val int) {
	n:=len(ft)
	for pos<n {
		ft[pos]+=val
		pos+=lowbit(pos)
	}
}

func get(ft []int, pos int) (ans int){
	ans=0
	for pos>0 {
		ans+=ft[pos]
		pos-=lowbit(pos)
	}
	return ans
}



func solve(cas int, in io.Reader, out io.Writer) {

	n:=0
	Fscan(in, &n)
	arr:=make([]int, n+1)
	pos:=make([]int, n+1)
	ft:=make([]int, n+1)
	for i:=1;i<=n;i++ {
		Fscan(in, &arr[i])
		pos[arr[i]] = i
		add(ft,i,1)
	}
	ans:=0
	for i:=1;i<=n;i++ {
		post:=get(ft, n) - get(ft, pos[i])
		pre:=get(ft,pos[i]-1) // how many greater element to the left
		ans+=min(post,pre)
		add(ft,pos[i],-1)
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
