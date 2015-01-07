#!/usr/bin/env python
"""Multiplayer Rock Paper Scissor

A minimal implementation of a Rock, Paper, Scissor game for two players.

Usage:
    Two players enter an option each, each argument representing a player.
    Argument 1 = Player 1
    Argument 2 = Player 2

Example:
    $ rps rock paper
    Player 2 wins!
    $ rps scissors paper
    Player 1 wins!

Python implementation by @mottosso

"""

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
