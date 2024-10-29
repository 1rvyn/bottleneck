use std::fs::File;
use std::io::{self, Read, Write};
use std::time::Instant;

fn main() -> io::Result<()> {
    let start = Instant::now();
    
    let mut input_file = File::open("../input.txt")?;
    let mut output_file = File::create("stream_output_rust.txt")?;
    
    let mut buffer = [0; 1]; // Reading one byte at a time
    loop {
        let bytes_read = input_file.read(&mut buffer)?;
        if bytes_read == 0 {
            break;
        }
        output_file.write_all(&buffer[..bytes_read])?;
    }
    
    let duration = start.elapsed();
    println!("Stream I/O Time taken: {:?}", duration);
    
    Ok(())
} 