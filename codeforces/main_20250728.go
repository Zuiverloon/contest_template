package main

/* https://codeforces.com/contest/1987/problem/C
*/

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
	n:=0
	Fscan(in, &n)
	v:=make([]int,n)
	for i:=0;i<n;i++{
		Fscan(in, &v[i])
	}	
	t:=0
	h:=0
	for i:=n-1;i>=0;i--{
		if i== n-1{
			t = 0
			h = v[i]
			// keeping droping from h at t second
		} else {
			if v[i]>h{
				gap:= v[i] - h
				if gap<t+1{
					t = t+1
				} else {
					t = 0
					h = v[i]
				}
			} else {
				gap:=h - v[i]
				t+=(gap+1)
				h = v[i]
			}
		}
	}
	fmt.Println(t+h)


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
