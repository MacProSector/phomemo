# Add executables
add_executable(
	phomemo
	phomemo.cpp
)
add_executable(
	test EXCLUDE_FROM_ALL
	test.cpp
)

# Set library link targets
target_link_libraries(
	phomemo
	phomemo_printer
	phomemo_utility
	${Boost_LIBRARIES}
)

# Set library link targets
target_link_libraries(
	test
	phomemo_printer
	phomemo_utility
	${Boost_LIBRARIES}
)

# Set installation targets
install(
	TARGETS phomemo
	RUNTIME DESTINATION bin
)
