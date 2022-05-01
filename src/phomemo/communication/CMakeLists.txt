# Add libraries
add_library(
	phomemo_communication SHARED
	serial.cpp
)

# Set header targets
file(GLOB PHOMEMO_COMMUNICATION_HEADERS "*.h" "*.hpp")

# Set library target properties
set_target_properties(
	phomemo_communication PROPERTIES
	PUBLIC_HEADER "${PHOMEMO_COMMUNICATION_HEADERS}"
)

# Set library link targets
target_link_libraries(
	phomemo_communication
	phomemo_utility
	${Boost_LIBRARIES}
)

# Set installation targets
install(
	TARGETS phomemo_communication
	LIBRARY DESTINATION lib
	PUBLIC_HEADER DESTINATION include/phomemo/communication
)