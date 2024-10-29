package main

import (
	"bufio"
	"fmt"
	"os"
	"time"
)

func main() {
	start := time.Now()

	file, err := os.Open("../../input.txt")
	if err != nil {
		fmt.Println("Error opening file:", err)
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		line := scanner.Text()
		_, err := fmt.Fprintln(os.Stdout, line)
		if err != nil {
			fmt.Println("Error writing to stdout:", err)
			return
		}
	}

	duration := time.Since(start)
	fmt.Printf("Time taken: %v\n", duration)
}
