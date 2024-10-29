use std::fs::File;
use std::io::{self, BufRead, Write};
use std::path::Path;
use std::time::Instant;

fn main() -> io::Result<()> {
    let start = Instant::now();
    let path = Path::new("../input.txt");
    
    let file = File::open(path)?;
    let reader = io::BufReader::new(file);
    
    // Process each line
    for line in reader.lines() {
        let line = line?;
        writeln!(io::stdout(), "{}", line)?;
    }
    
    let duration = start.elapsed();
    println!("Time taken: {:?}", duration);
    
    Ok(())
}