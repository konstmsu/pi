use rust_gpiozero::*;
use std::thread;
use std::time::Duration;

fn main() {
    let led = LED::new(2);

    for n in 1..21 {
        println!("Blinking {}", n);
        led.on();
        thread::sleep(Duration::from_millis(500));
        led.off();
        thread::sleep(Duration::from_millis(300));
    }

    println!("Finished")
}