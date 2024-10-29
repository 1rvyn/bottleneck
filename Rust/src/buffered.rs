use std::fs::File;
use std::io::{self, BufRead, BufReader, BufWriter, Write};
use std::time::Instant;

fn main() -> io::Result<()> {
    let start = Instant::now();
    
    let input_file = File::open("../input.txt")?;
    let reader = BufReader::new(input_file);
    
    let output_file = File::create("buffered_output_rust.txt")?;
    let mut writer = BufWriter::new(output_file);
    
    for line in reader.lines() {
        let line = line?;
        writeln!(writer, "{}", line)?;
    }
    
    writer.flush()?;
    
    let duration = start.elapsed();
    println!("Buffered I/O Time taken: {:?}", duration);
    
    Ok(())
} 