require("module")

function test_init(argv)
	print(argv);
	modulefunction(5); --example
	-- do something
end

function test_callc(value1, value2)
	local value3 = value1 + value2;
	cprintint(value3);
	cprintstr("Sent this string from Lua to C");
end
