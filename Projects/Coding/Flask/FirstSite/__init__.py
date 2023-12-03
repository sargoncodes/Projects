from flask import Flask, redirect, url_for, render_template, request, session, flash
from flask_sqlalchemy import SQLAlchemy

#Define Flask variables
app = Flask(__name__)
app.secret_key = "key"

#Define SQL variables
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///users.sqlite3'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)
 
#Creates class for SQL
class users(db.Model):
    _id = db.Column("id", db.Integer, primary_key=True)
    name = db.Column(db.String(100))
    bio = db.Column(db.String(100))

    def __init__(self, name, bio):
        self.name = name
        self.bio = bio

#Shortcuts for redirects
def go_start():
    return redirect(url_for("landing"))
def go_login():
    return redirect(url_for("login"))
def go_welcome():
    return redirect(url_for("user"))

#App routes
@app.route("/", methods=["POST", "GET"])
def landing():
    
    if request.method == "POST":
        user = request.form["nm"]
        
        if "" == user:
            session["user"] = "guest"
            return go_welcome()
        
        session["user"] = user
        flash("Session started")
        found_user = users.query.filter_by(name=user).first()
        
        if found_user:
            session["bio"] = found_user.bio
            flash("Credentials found | session held")
            return go_welcome()
        
        else:
            usr = users(user, "")
            db.session.add(usr)
            db.session.commit()
            flash("Name saved | session started")
            
        return go_login()
    
    else:
        return render_template("landing.html")
    
@app.route("/login", methods=["POST", "GET"])
def login():
    bio = None
    
    if "user" in session:
        
        user = session["user"]
        
        if request.method == "POST":
            bio = request.form["bio"]
            session["bio"] = bio
            found_user = users.query.filter_by(name=user).first()
            found_user.bio = bio
            db.session.commit()
            flash("Credentials saved | session held")
            return go_welcome()
        
        else:
            
            if "bio" in session:
                
                bio = session["bio"]
        return render_template("login.html", name=f", {user}")
    
    else:
        
        return go_start()
    
@app.route("/welcome", methods=["POST", "GET"])
def user():
    
    if "user" in session:
        user = session["user"]
        return render_template("index.html", name=f", {user}")
    
    else:
        return go_start()
    
@app.route("/deleteme", methods=["POST", "GET"])
def deleteme():
    
    if "user" in session and "user" != "guest":
        user = session["user"]
        usr = users.query.filter_by(name=user).first()
        db.session.delete(usr)
        db.session.commit()
        flash("Credentials deleted succesfully")
        return redirect(url_for("logout"))
    
    else:
        flash("You're not logged in | nothing deleted")
        return go_start()

@app.route("/logout")
def logout():
    if "user" in session:
        
        session.pop("user", None)
        session.pop("bio", None)
        flash("You have been logged out | session cleared")
    else:
        
        flash("You're not logged in | no session", "error")
        
    return go_start()

@app.route("/view")
def view():
    
    if "user" in session:
        user = session["user"]
        return render_template("view.html", values=users.query.all(), name=f", {user}")
    
    else:
        
        return go_start()

@app.route("/admin", methods=["POST", "GET"])
def admin():
    
    if "user" in session:
        user = session["user"]
        
        if user == "James":
            
            if request.method == "POST":
                
                try:
                    id = request.form["id"]
                    target = users.query.filter_by(_id=id).first()
                    db.session.delete(target)
                    db.session.commit()
                    flash('User was removed successfully')
                    
                except:
                    flash("Something went wrong", "error")
                    
            return render_template("admin.html", name=", admin")
        
    return redirect(url_for("goober"))

@app.route("/goober")
def goober():
    
    if "user" in session:
        user = session["user"]
        return render_template("goober.html", name=f", {user}")
    
    else:
        return render_template("goober.html")

#Starts application and creates SQL db
if __name__ == "__main__":
    
    with app.app_context():
        db.create_all()
        
    app.run(debug=True, host="0.0.0.0", port=8080)