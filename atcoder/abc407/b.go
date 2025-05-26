package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

// func readLine() string {
// 	reader := bufio.NewReader(os.Stdin)
// 	text, _ := reader.ReadString('\n')
// 	return strings.Trim(text, "\n")
// }

// func printArr(arr []int) {
// 	n := len(arr)
// 	for id, i := range arr {
// 		Printf("%d", i)
// 		if id < n-1 {
// 			Printf(" ")
// 		} else {
// 			Printf("\n")
// 		}
// 	}
// }

// func readIntArray() []int {
// 	text := readLine()
// 	sli := strings.Split(text, " ")
// 	ret := make([]int, len(sli))
// 	for i, s := range sli {
// 		ret[i], _ = strconv.Atoi(s)
// 	}
// 	return ret
// }

// func readInt() int {
// 	text := readLine()
// 	ret, _ := strconv.Atoi(text)
// 	return ret
// }

// func readStringArray() []string {
// 	text := readLine()
// 	sli := strings.Split(text, " ")
// 	ret := make([]string, len(sli))
// 	for i, s := range sli {
// 		ret[i] = s
// 	}
// 	return ret
// }

func ioSample(in io.Reader, out io.Writer) {
	var x, y int
	Fscan(in, &x, &y)

	Fprint(out, 1)
}

func solve(cas int, in io.Reader, out io.Writer) {
	var x, y int
	Fscan(in, &x, &y)
	a1 := 0
	for i := 1; i <= 6; i++ {
		for j := 1; j <= 6; j++ {
			if i+j >= x || (i-j <= -y || i-j >= y) {
				a1++
			}
		}
	}

	Fprint(out, float64(a1)/36.0)

}

func main() {
	n := 1
	input := bufio.NewReader(os.Stdin)
	//Fscan(input, &n)

	i := 0
	for ; i < n; i++ {
		solve(i, input, os.Stdout)
	}

}
