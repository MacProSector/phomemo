# Add libraries
add_library(
	phomemo_printer SHARED
	printer.cpp
)

# Set header targets
file(GLOB PHOMEMO_PRINTER_HEADERS "*.h" "*.hpp")

# Set library target properties
set_target_properties(
	phomemo_printer PROPERTIES
	PUBLIC_HEADER "${PHOMEMO_PRINTER_HEADERS}"
)

# Set library link targets
target_link_libraries(
	phomemo_printer
	phomemo_utility
	${Boost_LIBRARIES}
)

# Set installation targets
install(
	TARGETS phomemo_printer
	LIBRARY DESTINATION lib
	PUBLIC_HEADER DESTINATION include/phomemo/printer
)