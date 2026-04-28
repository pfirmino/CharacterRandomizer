using Microsoft.AspNetCore.Mvc;

namespace CharacterRandomizerServerLinux.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class AvatarController : ControllerBase
    {
        // GET api/avatar
        [HttpGet]
        public IActionResult Get()
        {
            Random rnd = new Random();

            var response = new
            {
                Succeed = true,
                SkinColorInt = rnd.Next(0, 3),
                UpperBodyInt = rnd.Next(0, 4),
                LowerBodyInt = rnd.Next(0, 4),
                EyesColorInt = rnd.Next(0, 4),
                HairStyleInt = rnd.Next(0, 4),
                HairColorInt = rnd.Next(0, 6),
                HandsInt = rnd.Next(0, 2),
                FeetInt = rnd.Next(0, 2),
                BodyTypeFloat = rnd.NextDouble()
            };

            return Ok(response);
        }

        // GET api/avatar/5
        [HttpGet("{id}")]
        public IActionResult Get(int id)
        {
            return Ok("value");
        }

        // POST api/avatar
        [HttpPost]
        public IActionResult Post([FromBody] string value)
        {
            return Ok();
        }

        // PUT api/avatar/5
        [HttpPut("{id}")]
        public IActionResult Put(int id, [FromBody] string value)
        {
            return Ok();
        }

        // DELETE api/avatar/5
        [HttpDelete("{id}")]
        public IActionResult Delete(int id)
        {
            return Ok();
        }
    }
}