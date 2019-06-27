use rust_gpiozero::*;
use std::thread;
use std::time::Duration;

fn main() {
    let leds = [LED::new(2), LED::new(3), LED::new(4)];

    for i in 0..20 {
        println!("Blinking {}", i);
        let led = &leds[i % leds.len()];
        led.on();
        thread::sleep(Duration::from_millis(300));
        led.off();
        thread::sleep(Duration::from_millis(200));
    }

    println!("Finished")
}