# pvt-box

pvt-box is a cross-platformed static file server written in C++.  

Currently, it is still under heavy development. 

## Getting Started
### Prerequisites


The project is compatible with Window, macOS and Linux. [Boost](http://boost.org) is a 
mandatory dependency for pvt-box to compile and execute successfully. 

Besides, your computer needs CMake to build the project. 

### Compilation 


```bash
git clone https://github.com/patrickwang96/pvt-box.git
cd pvt-box
cmake . 
make pbox
```

### Usage

```bash
./pbox <address> <port> <root_directory> &
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

Open sourced under MIT license, the terms of which can be read here — [MIT License](http://opensource.org/licenses/MIT).