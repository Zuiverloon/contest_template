package main

/** http://codeforces.com/contest/2057/problem/C
**/


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

func gethigh(l int)int{
	ans:=0
	for ;l>0;l>>=1{
		ans<<=1
		if ans == 0{
			ans = 1
		}
	}
	return ans
}

func f(l int, r int) []int {
	if r-l == 2{
		v:=make([]int,3)
		v[0] = l
		v[1] = l+1
		v[2] = l+2
		return v
	}
	highl := gethigh(r)
	if (highl & l) == highl {
		next:=f(l-highl, r-highl)
		next[0]+=highl
		next[1]+=highl
		next[2]+=highl
		return next
	} else {
		if highl == r{
			ans:=make([]int,3)
			ans[0] = r-2
			ans[1] = r-1
			ans[2] = r
			return ans
		} else {
			ans:=make([]int,3)
			ans[0] = r
			ans[1] = highl
			ans[2] = highl-1
			return ans
		}

	}
}


func solve(cas int, in io.Reader, out io.Writer) {
	var l, r int
	Fscan(in, &l)
	Fscan(in, &r)
	ans:=f(l,r)
	fmt.Printf("%d %d %d\n",ans[0],ans[1],ans[2])


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
