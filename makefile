.DEFAULT_GOAL := build

build:
	arduino --verify FightboardHybrid.ino --board arduino:avr:leonardo -v

upload:
	arduino --upload FightboardHybrid.ino --board arduino:avr:leonardo -v
