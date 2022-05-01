# Add executables
add_executable(phomemo phomemo.cpp)

# Set installation targets
install(
	TARGETS phomemo
	RUNTIME DESTINATION bin
)
