open Framework;
open TennisKata.Game;




describe("Test Game transitions", ({test}) => {
  test("Given PlayerOne then PlayerTwo is different", ({expect}) => {
    expect.notEqual(PlayerOne, PlayerTwo)
  })
});

describe("Test Game transitions", ({test}) => {
  test("Given deuce when PlayerOne wins then score is correct", ({expect}) => {
    expect.equal(scoreWhenDeuce(PlayerOne), Advantage(PlayerOne))
  })
});

describe("Testing advantage win", ({test}) => {
  test(
    "Given advantage when advantaged player wins then score is correct",
    ({expect}) => {
    let advantagedPlayer = PlayerOne;
    let winner = advantagedPlayer;
    expect.equal(
      scoreWhenAdvantage(advantagedPlayer, winner),
      Game(advantagedPlayer),
    );
  })
});

describe(
  "Given advantage when the other player wins then score is Deuce", ({test}) => {
  test(
    "Given advantage when the other player wins then score is Deuce",
    ({expect}) => {
    let advantagedPlayer = PlayerOne;
    let winner = other(advantagedPlayer);
    expect.equal(scoreWhenAdvantage(advantagedPlayer, winner), Deuce);
  })
});

describe(
  "Given player: 40 when wins then score is Game for this player", ({test}) => {
  test(
    "Given player: 40 when wins then score is Game for this player",
    ({expect}) => {
    let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
    expect.equal(
      scoreWhenForty(fortyThirty, fortyThirty.player),
      Game(fortyThirty.player),
    );
  })
});

describe(
  "Given player: 40 | other : 30 when other wins then score is Deuce",
  ({test}) => {
  test(
    "Given player: 40 | other : 30 when other wins then score is Deuce",
    ({expect}) => {
    let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
    expect.equal(
      scoreWhenForty(fortyThirty, other(fortyThirty.player)),
      Deuce,
    );
  })
});





describe(
  "Given player: 40 | other : 0 when other wins then score is fortyFifteen",
  ({test}) => {
  test(
    "Given player: 40 | other : 0 when other wins then score is fortyFifteen",
    ({expect}) => {
    let fortyLove = {player: PlayerOne, otherPlayerPoint: Love};
    let fortyFifteen = {player: PlayerOne, otherPlayerPoint: Fifteen};
    expect.equal(
      scoreWhenForty(fortyLove, other(fortyLove.player)),
      Forty(fortyFifteen),
    );
  })
});

describe("Wins tests", ({test}) => {
  test(
    "Given player: 0 | other : 15 when other wins then score is 0/30",
    ({expect}) => {
    let loveFifteen = {playerOne: Love, playerTwo: Fifteen};
    let loveThirty = {playerOne: Love, playerTwo: Thirty};
    expect.equal(
      scoreWhenPoints(loveFifteen, PlayerTwo),
      Points(loveThirty),
    );
  });
  test(
    "Given player: 30 | other : 15 when player wins then score is 40/15",
    ({expect}) => {
    let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
    let fortyFifteen = {player: PlayerOne, otherPlayerPoint: Fifteen};
    expect.equal(
      scoreWhenPoints(thirtyFifteen, PlayerOne),
      Forty(fortyFifteen),
    );
  });
});