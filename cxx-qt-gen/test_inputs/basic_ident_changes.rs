mod my_object {
    #[derive(Default)]
    struct Data {
        my_number: i32,
    }

    #[derive(Default)]
    struct RustObj;

    impl RustObj {
        #[invokable]
        fn say_bye(&self) {
            println!("Bye from Rust!");
        }
    }
}
