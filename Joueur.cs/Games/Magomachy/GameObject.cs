// An object in the game. The most basic class that all game classes should inherit from automatically.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
// <<-- Creer-Merge: usings -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional using(s) here
// <<-- /Creer-Merge: usings -->>

namespace Joueur.cs.Games.Magomachy
{
    /// <summary>
    /// An object in the game. The most basic class that all game classes should inherit from automatically.
    /// </summary>
    public class GameObject : BaseGameObject
    {
        #region Properties
        /// <summary>
        /// Any strings logged will be stored here. Intended for debugging.
        /// </summary>
        public IList<string> Logs { get; protected set; }


        // <<-- Creer-Merge: properties -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional properties(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: properties -->>
        #endregion


        #region Methods
        /// <summary>
        /// Creates a new instance of GameObject. Used during game initialization, do not call directly.
        /// </summary>
        protected GameObject() : base()
        {
            this.Logs = new List<string>();
        }

        /// <summary>
        /// Adds a message to this GameObject's logs. Intended for your own debugging purposes, as strings stored here are saved in the gamelog.
        /// </summary>
        /// <param name="message">A string to add to this GameObject's log. Intended for debugging.</param>
        public void Log(string message)
        {
            this.RunOnServer<object>("log", new Dictionary<string, object> {
                {"message", message}
            });
        }



        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
        #endregion
    }
}
