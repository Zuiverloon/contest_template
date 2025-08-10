package main

// 

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

func makeline(x1 int, y1 int, x2 int, y2 int)[]int {
	ans:=make([]int, 3)

	if x1 == x2 {
		ans[0] = 1
		ans[1] = 0
		ans[2] = x1
	} else if y1 == y2{
		ans[0] = 0
		ans[1] = 1
		ans[2] = y1
	} else {
		dx := x1 - x2
		dy := y1 - y2
		gd:=gcd(dx,dy)
		dx/=gd
		dy/=gd
		if dy>0 {
			dx*=-1
			dy*=-1
		}
		ans[0] = -dy
		ans[1] = dx
		ans[2] = dy*x1+dx*y1
	}
	return ans
}

func check1(lines [][]int, dim int)int {
	ans:=0
	n:=len(lines)
	px:=-0x3f3f3f3f
	py:=-0x3f3f3f3f
	con:=0
	for i:=0;i<n;i++{
		if lines[i][dim] == px && lines[i][dim+1] == py {
			con++
		} else {
			// fmt.Println("con=",con)
			ans+=con*(con-1)/2
			con = 1
			px = lines[i][dim]
			py = lines[i][dim+1]
		}
	}
	ans+=con*(con-1)/2
	return ans
}
func check2(lines [][]int)int {
	ans:=0
	n:=len(lines)
	px:=-0x3f3f3f3f
	py:=-0x3f3f3f3f
	pz:=-0x3f3f3f3f
	con:=0
	for i:=0;i<n;i++{
		if lines[i][0] == px && lines[i][1] == py && lines[i][2] == pz {
			con++
		} else {
			ans+=con*(con-1)/2
			con = 1
			px = lines[i][0]
			py = lines[i][1]
			pz = lines[i][2]
		}
	}
	ans+=con*(con-1)/2
	return ans
}



func solve(cas int, in io.Reader, out io.Writer) {
	var n int
	Fscan(in,&n)
	a:=make([][]int,n)
	lines:=make([][]int, (n-1)*(n)/2)
	for i:=0;i<n;i++{
		a[i] = make([]int,2)
		Fscan(in,&a[i][0])
		Fscan(in,&a[i][1])
	}
	lp:=0
	for i:=0;i<n;i++{
		for j:=i+1;j<n;j++{
			lines[lp] = make([]int,5)
			line:=makeline(a[i][0],a[i][1],a[j][0],a[j][1])
			// fmt.Println(a[i][0],a[i][1],a[j][0],a[j][1], line[0], line[1], line[2])
			lines[lp][0] =line[0]
			lines[lp][1] =line[1]
			lines[lp][2] =line[2] 
			lines[lp][3] =a[i][0]+a[j][0]
			lines[lp][4] =a[i][1]+a[j][1]
			lp++
		}
	}
	sort.Slice(lines,func(i int, j int)bool{
		if lines[i][0]!=lines[j][0] {
			return lines[i][0]<lines[j][0]
		} else {
			return lines[i][1]<lines[j][1]
		}
	})
	ans:=0
	// fmt.Println(lines)

	ans+=check1(lines,0)
	// ans-=check2(lines)
	sort.Slice(lines,func(i int, j int)bool{
		if lines[i][3]!=lines[j][3] {
			return lines[i][3]<lines[j][3]
		} else {
			return lines[i][4]<lines[j][4]
		}
	})
	ans-=check1(lines,3)
	fmt.Println(ans)

	


}


func main() {
	n := 1
	

	// n = readIntArray()[0]
	in:=bufio.NewReader(os.Stdin)
	// Fscan(in, &n)

	i := 0
	for ; i < n; i++ {
		solve(i, in, os.Stdout)
	}

}
