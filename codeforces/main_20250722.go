package main

import (
	"bufio"
	"fmt"
	. "fmt"
	"io"
	"os"
	// "sort"
)

func printArr[T any](arr []T){
	l := len(arr)
	for i:=0;i<l;i++{
		fmt.Print(arr[i])
		if i<l-1{
			fmt.Print(" ")
		} else {
			fmt.Print("\n")
		}
	}
}



func ioSample(in io.Reader, out io.Writer) {
	var x, y int
	Fscan(in, &x, &y)

	Fprint(out, 1)
}

func printYES() {
	fmt.Println("YES")
}
func printNO() {
	fmt.Println("NO")
}

func printYes() {
	fmt.Println("Yes")
}
func printNo() {
	fmt.Println("No")
}
// sort sort.Ints()


func solve(cas int, in io.Reader, out io.Writer) {
	var n int
	Fscan(in,&n)
	v:=make([]int, n)
	mp:= make([]int, n+1)
	dpcnt := 0
	for i:=0;i<n;i++{
		Fscan(in, &v[i])
		mp[v[i]]++
	}
	dp:=make([]int, n+1)
	greater:=make([]int, n+1)

	tot:=n
	for i:=0;i<=n;i++{
		dp[i] = dpcnt
		greater[i] = tot-mp[i]
		if mp[i]>1{
			dpcnt += (mp[i]-1)
		}
		tot-=mp[i]
	}
	// sort.Ints(v)
	mex := 0
	for i:=0;i<=n;i++{
		if mp[i]==0{
			mex = i
			break
		}
	}

	ans:=make([]int, n+1)
	
	for i:=0;i<=mex;i++{
		mn:=mp[i]
		mx:=mp[i]+dp[i]+greater[i]
		ans[mn]++
		if mx+1<=n{
			ans[mx+1]--
		}
	}
	pre:=0
	for i:=0;i<=n;i++{
		pre+=ans[i]
		ans[i] = pre
	}
	printArr(ans)

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
