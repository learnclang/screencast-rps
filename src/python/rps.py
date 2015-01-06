#!/usr/bin/env python
"""python implementation by @mottosso"""
import argparse
choices = ["rock", "paper", "scissors"]

parser = argparse.ArgumentParser()
parser.add_argument("player1", choices=choices)
parser.add_argument("player2", choices=choices)

args = parser.parse_args()

beats = {"rock": "scissors",
         "paper": "rock",
         "scissors": "paper"}

if beats[args.player1] == args.player2:
    print "Player 1 wins!"
else:
    print "Player 2 wins!"
