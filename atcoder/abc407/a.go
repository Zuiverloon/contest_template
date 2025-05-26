package main

    import(
        "bufio"
            ."fmt"
             "io"
             "math"
             "os")

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

    func ioSample(in io.Reader, out io.Writer){
        var x, y int
                   Fscan(in, &x, &y)

                       Fprint(out, 1)}

func solve(cas int, in io.Reader, out io.Writer)
{
    var x, y int
           Fscan(in, &x, &y)
               var target float64
                   target = 1.0 * float64(x) / (1.0 * float64(y)) if math.Abs(float64(x / y) - target) < math.Abs(float64(x / y + 1) - target)
    {
        Fprint(out, x / y)
    }
    else
    {
        Fprint(out, x / y + 1)
    }
}

func main()
{
n:= 1
	input := bufio.NewReader(os.Stdin)
	//Fscan(input, &n)

	i := 0
	for ;
    i < n;
    i++
    {
        solve(i, input, os.Stdout)
    }
}
