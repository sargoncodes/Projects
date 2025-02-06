from flask import Flask, render_template, request, redirect, url_for, flash
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
    _id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(100))
    number = db.Column(db.String(100))

    def __init__(self, name, number):
        self.name = name
        self.number = number


#App routes
@app.route("/")
def landing():
    return render_template("index.html")

@app.route("/rsvp", methods=["POST", "GET"])
def rsvp():
    user = False
    number = False
    index = False
    
    if request.method == "POST":
        try:
            user = request.form['name']
            number = request.form['number']
        except:
            try:
                index = request.form['index']
            except:
                pass
        pass

        if (user and index) or (number and index):
            flash("Error: Users cannot be added and removed at the same time")
        elif (user and not number) or (number and not user):
            flash("Error: Please fill in both feilds")
        elif user and number:
            new = users(user, number)
            db.session.add(new)
            flash("Successfully added")
        elif index:
            kill = users.query.filter_by(_id=index).first()
            db.session.delete(kill)
            flash("Successfully removed")
        else:
            flash("Error: Endpoint error")
#        db.session.commit()
        return redirect(url_for("rsvp"))
        
    return render_template("rsvp.html") #, values=users.query.all()

#Starts application and creates SQL db
if __name__ == "__main__":
    
    with app.app_context():
        db.create_all()
        
    app.run(debug=True, host="0.0.0.0", port=5000)